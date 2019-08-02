#include <iostream>
#include<random>
#include <vector>
#include <algorithm>
using namespace std;
int random_number_not_in_list(vector<int>,int);
int main() {
  vector<int> testcase1;
  testcase1.push_back(5);
  testcase1.push_back(2);
  testcase1.push_back(1);
  cout<<random_number_not_in_list(testcase1,7)<<endl;

  return 0;
}

int random_number_not_in_list(vector<int> l,int n){
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist(0,n-1);
  auto random = dist(mt);
  bool found = std::find(l.begin(), l.end(), random) != l.end();
  
  if (found){
    return random_number_not_in_list(l,n);
  }
  return random;
}
