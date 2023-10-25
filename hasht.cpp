#include<iostream>
#include<list>
#include<string>
using namespace std;

class HashTable{
    private:
    static const int hashSize = 10;
    list<pair<int, string>> table[hashSize];

    public:
    bool isEmpty() const;
    int hashFunction(int key);
    //DataItem* hashFunction(int key);
    void insert(int key, string val);
    void remove(int key);
    void disp();
};

bool HashTable::isEmpty() const{
    int sum{};
    for(int i{}; i<hashSize; i++){
        sum+= table[i].size();
    }
    if(sum==0){
        return true;
    }
    else{
        return false;
    }
}

int HashTable::hashFunction(int key) {
    return key % hashSize;
}

/*DataItem* HashTable::hashFunction(int key) {
    int hashIndex = hashCode(key);
    while(table[hashIndex]=! 0){
        if(table[hashIndex]->key == key) {
            return table[hashIndex];
        }
            ++hashIndex;
            hashIndex %= hashSize;
    }
    return nullptr;
}*/

void HashTable::insert(int key, string val) {
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for(; bItr!=end(cell); bItr++){
        if(bItr->first == key){
            keyExists = true;
            bItr->second = val;
            cout<<"Value has been replaced"<<endl;
            break;
        }
    }
    if(keyExists==0){
        cell.emplace_back(key, val);
    }
    return;
}
int main()
{
    HashTable h;
    h.insert(5,"yes");
    if(h.isEmpty()==false)
    {
        cout<<"tinga lak lak";
    }
    else{
        cout<<"cri";
    }
}