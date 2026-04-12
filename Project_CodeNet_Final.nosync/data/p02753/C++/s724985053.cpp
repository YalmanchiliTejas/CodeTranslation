//
//  main.cpp
//  ProgrammingContestChallengeBook2
//
//  Created by Hisaki Kobayashi on 2020/04/04.
//  Copyright © 2020 Hisaki Kobayashi. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>
//#include "mylibrary.hpp"



using namespace std;


int main(){
    string S; cin >> S;
    if(S[0]=='B' && S[1]=='B' && S[2]=='B')
        cout << "No" << endl;
    else if(S[0]=='A' && S[1]=='A' && S[2]=='A')
        cout << "No"<< endl;
    else{
        cout << "Yes"<< endl;
    }
}
