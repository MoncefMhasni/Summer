#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define cv stoi
#define all(v) (v.begin(),v.end())
using namespace std;
void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

int main(){
    string s;
    while(getline(cin,s)){
        string a;
        stringstream ss(s);
        int ans=0;
        while(ss>>a){
            vector<string> v;
            split(a,':',v);
            if(v[0].find('-')==string::npos){
                ans += cv(v[1]);
            }

            if(v[0].find('-')!=string::npos){
                            vector<string> x;
                            split(v[0],'-',x);
                            ans += (1+cv(x[1])-cv(x[0]))*cv(v[1]);
            }

        }
        cout<<ans<<endl;
    }

}
