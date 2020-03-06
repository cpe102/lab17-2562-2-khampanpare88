//Write your code here
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>
#include<cctype>
using namespace std;

string upper(string s){
    for(int i=0;i<s.size();i++){
        s[i]=toupper(s[i]);
    }
    return s;
}
int main(){
    vector<string> v_name;
    vector<string> v_grade;
    vector<int> v_score;
    ifstream f("name_score.txt");
    string s;
    int num,num1,num2,num3;
    char name[100];
    while (getline(f,s)){
        sscanf( s.c_str() , "%[^:]: %d %d %d" , name , &num1 , &num2 , &num3 );
        v_name.push_back(name);
        num = num1+num2+num3;
        v_score.push_back(num);
    }
    f.close();
    for(int i=0;i<=v_score[i];i++){
        if(v_score[i]>=80) {
            v_grade.push_back("A");
        }
        else if(v_score[i]>=70 && v_score[i]<=79){
            v_grade.push_back("B");
        }
        else if(v_score[i]>=60 && v_score[i]<=69){
            v_grade.push_back("C");
        }
        else if(v_score[i]>=50 && v_score[i]<=59){
            v_grade.push_back("D");
        }
        else{v_grade.push_back("F"); }
    }
    while(true){
        cout<<"Plase input your command : ";
        getline(cin,s);
        int idx = s.find_first_of(" ");
        string s1 = upper( s.substr(0,idx));
        string s2 = upper( s.substr(idx+1, s.size()));
        if(s1 == "NAME"){
            if(true){
                for(int i = 0 ; i < v_name.size() ; i++ ){
                    if(s2 == upper(v_name[i])){
                        cout << "\n------------------------------------\n";
                        cout << v_name[i] << "'s grade = " << v_grade[i] ;
                        cout << "\n------------------------------------\n";
                    }
                }
            }
            else {
                cout << "Cannot found.\n";
            }
            
        }
        else if(s1 == "GRADE"){
            if(true){
                cout << "\n------------------------------------\n";
                for(int i = 0 ; i < v_grade.size() ; i++ ){
                    if(s2 == v_grade[i]){
                        
                        cout << v_name[i]<<"\n";
                        
                    }
                }
                cout << "\n------------------------------------\n";
            }
            else {
                cout << "Cannot found.\n";
            }
            
        }
        else if(s1 == "EXIT") break;
        else{
            cout << "Invilid command.\n" ;
        }
    }
} 
