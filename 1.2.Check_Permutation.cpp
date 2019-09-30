# include <string>
# include <vector>
# include <iostream>
# include <bitset>
# include <algorithm> // For sort()

using namespace std;

//First Approch: Sort , Compare
bool arePermutations(string str1, string str2){
    //Get lenght of each of them 
    int n1 = str1.length();
    int n2 = str2.length();
    if(n1!=n2)
        return false;
    
    //Sort both of them 
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    
    //Compare
    for (int i = 0 ; i < n1 ; i++){
        if(str1[i]!=str2[i])
            return false;
    }
    return true;
}

//Second Approach:Character Count
bool arePermutations_2(const string &str1, const string &str2){
    if(str1.length()!=str2.length())
        return false;
    int count[256] = {0};
    for (int i=0; i<str1.length();i++){
        int val = str1[i];
        count[val]++;
        
    }
    for (int i=0; i<str2.length();i++){
        int val = str2[i];
        count[val]--;
        if(count[val]<0)
            return false;
    }
    return true;
}

int main(){
    //Test Method 1 - Using Sort
    cout << "Method 1 - Using Sort" << endl;
    string str1 = "Testest";
    string str2 = "estexst";
    if(arePermutations(str1,str2))
        cout << str1 <<" and "<< str2 << " are permutatiom of eachother" << endl;
    else
        cout << str1 <<" and "<< str2 << " are not permuation of eachother" << endl;
    str1 = "hello";
    str2 = "oellh";
    if(arePermutations(str1, str2))
      cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;
    
    cout << endl;  
      
    //Test Method 2 - Using character count
    cout << "Method 2 - Using character count" << endl;
    str1 = "testest";
    str2 = "estxest";
    if(arePermutations_2(str1, str2))
      cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;
    str1 = "hello";
    str2 = "oellh";
     if(arePermutations_2(str1, str2))
      cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;
    return 0;
    
    return 0;
}
