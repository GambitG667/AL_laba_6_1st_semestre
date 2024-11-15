#include "lab.hpp"
#include <list>
#include <queue>
#include <vector>
#include <set>


std::vector<int>::iterator Find(std::vector<int>::iterator first, std::vector<int>::iterator last, int el){
    while(first != last){
        if(*first == el){
            return first;
        }
        first += 1;
    }
    return last;
}

std::vector<int>::iterator findInSorted(std::vector<int>::iterator first, std::vector<int>::iterator last, int el){
    std::vector<int>::iterator a = first;
    std::vector<int>::iterator b = last;
    std::vector<int>::iterator c = first;
    while(a != b-1){
        c = a + (b-a)/2;
        if(*c == el) return c;
        *c > el ? b = c : a = c;
    }
    return last;
}

int wordsCounter(const std::string& str){
    if (str == "") return 0;
    int count = 1;
    for(int i{}; i < str.size(); ++i){
        if(str.at(i) == ' ' || str.at(i) == '.' || str.at(i) == ','){
            count += 1;
        }
    }
    return count;
}

std::map<std::string, int> wordsMapCounter(const std::string& str){
    std::map<std::string, int> words;
    int index = 0;
    for(int i{}; i < str.size(); ++i){
        if(str.at(i) == ' ' || str.at(i) == '.' || str.at(i) == ','){
            std::string substring = str.substr(index, i-index);
            if(words.find(substring) == words.end()) words[substring] = 1;
            else words[substring] += 1;
            index = i + 1;
        }
    }
    std::string substring = str.substr(index, str.size()-index);
    if(words.find(substring) == words.end()) words[substring] = 1;
    else words[substring] += 1;
    
    return words;
}

std::vector<std::string> uniqueWords(const std::string& str){
    std::set<std::string> unic_words;
    int index{0};
    for(int i{}; i < str.size(); ++i){
        if(str.at(i) == ' ' || str.at(i) == '.' || str.at(i) == ','){
           unic_words.insert(str.substr(index, i-index));
           index = i + 1; 
        }
    }
    unic_words.insert(str.substr(index, str.size()-index));
    return std::vector(unic_words.begin(), unic_words.end());
}

int diffWordsCounter(const std::string& str){
    return uniqueWords(str).size();
}

void reverseNum(std::vector<int> &numbers){
    std::vector<int> result;
    for(auto i: numbers){
        result.push_back(-i);
        result.push_back(i);
    }
    numbers = result;
}

void plusesDeleter(std::vector<int> &numbers){
    std::vector<int> result;
    for(auto i: numbers){
        if(i<=0) result.push_back(i);
    }
    numbers = result;
}

/* Сортировка объединением, список разбивается на списки из одного элемента, 
а затем они по-парно объединяются. первые элементы исходных списков сравниваются,
наименьший из них переносится в результирующий список, если один из списков
заканчивается, оставшиеся элементы во втором добавляются в конец результата

Этот алгоритм оптимален для std::list, поскольку это двусвязный список и 
при разбиении на несколько разных списков и при объединении их в один
копирование данных не происходит.
*/
void Sort(std::list<int> &list){
    std::queue<std::list<int>> queue;
    while(list.size()!=0){
        std::list<int>::iterator pos = list.begin();
        ++pos;
        std::list<int> new_list;
        new_list.splice(new_list.begin(), list,list.begin(), pos);
        queue.push(new_list);
    }
    while(queue.size() != 1){
        std::list<int> a = queue.front();
        queue.pop();
        std::list<int> b = queue.front();
        queue.pop();

        std::list<int> result;
        while(!a.empty() && !b.empty()){
            if(*a.begin() < *b.begin()){
                std::list<int>::iterator pos = a.begin();
                ++pos;
                result.splice(result.end(), a, a.begin(), pos);
            }else{
                std::list<int>::iterator pos = b.begin();
                ++pos;
                result.splice(result.end(), b, b.begin(), pos);
            }
        }
        if(!a.empty()){
            result.splice(result.end(), a);
        }else if(!b.empty()){
            result.splice(result.end(), b);
        }
        queue.push(result);
    }
    list.splice(list.begin(), queue.front());

}