#include <iostream>
#include <vector>
#include "lab.hpp"


int main(){
    std::vector<int> vector = {0,1,2,3,4,5,6,7,8,9};
    
    std::cout << *Find(vector.begin()+1, vector.begin()+5,2)<<std::endl;

    std::cout << *findInSorted(vector.begin(), vector.end(), 5)<<std::endl;

    std::cout << wordsCounter("hello yopta,Hello.hello") << std::endl;

    for (auto pair: wordsMapCounter("can hello can Hello can")){
        std::cout << pair.first << " : " << pair.second << std::endl;
    }

    for (auto word: uniqueWords("hello,can,hello,do")){
        std::cout << word << ' ';
    }
    std::cout << std::endl;

    reverseNum(vector);

    for (auto i: vector){
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    plusesDeleter(vector);
    
    for (auto i: vector){
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    std::list<int> list = {3,4,5,1,8,6,-1};
    Sort(list);
    for(auto i:list) std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}