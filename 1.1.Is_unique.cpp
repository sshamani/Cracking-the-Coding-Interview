# include <string>
# include <vector>
# include <iostream>
# include <bitset>
# include <algorithm> // For sort()

using namespace std;

//Approach 1:
bool isUniqueChars(const string &str){
    if(str.length()>128){ 
        return false;
    }
    vector<bool> char_set(128);
    for(int i=0;i<str.length();i++){
        int val = str[i];
        if(char_set[val]){
            return false;
        }
        char_set[val] = true;
    }
    return true;
}

//Aproach 2:
bool isUniqueChars_noDS(string str){
    sort(str.begin(), str.end()); //O(nlogn) sort from <algorithm>
    
    bool noRepeat = true;
    for(int i = 0 ; i<str.length()-1;i++){
        if(str[i] == str[i-1]){
            noRepeat = false;
            break;
        }
    }
    return noRepeat;
}
int main(){
    vector<string> words={"abcde", "hello", "apple", "kite", "padle"};
    cout << "Aprroach 1: Using additional vector" << endl;
    for(auto word:words)
    {
        cout << word << string(": ") << boolalpha << isUniqueChars(word) << endl;
    }
    cout << "Approach 2: Using no extra Data Structure!" << endl ; 
    for(auto word:words)
    {
        cout << word << string(":") << boolalpha << isUniqueChars_noDS(word) << endl;
    }
    return 0;
}
