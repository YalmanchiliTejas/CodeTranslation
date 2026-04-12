/*
 * ----------------------------------------------------------------------------
 *  (: Bismillahir Rahmanir Rahim :) 
 * File: /home/grim/Programming/Atcoder/Today/C_Sum_of_product_of_pairs.cpp
 * Project: /home/grim/Programming/Atcoder/Today
 * Created Date: Saturday, August 29th 2020, 6:17:26 pm
 * Author: Grim Firefly :)
 * Author Mail : GrimFirefly1@gmail.com
 * -----
 * Last Modified: Sat Aug 29 2020
 * Modified By: Grim Firefly :)
 * -----
 *   ________        .__           ___________.__                  _____ .__          
 *  /  _____/_______ |__|  _____   \_   _____/|__|_______   ____ _/ ____\|  |  ___.__.
 * /   \  ___\_  __ \|  | /     \   |    __)  |  |\_  __ \_/ __ \\   __\ |  | <   |  |
 * \    \_\  \|  | \/|  ||  Y Y  \  |     \   |  | |  | \/\  ___/ |  |   |  |__\___  |
 *  \______  /|__|   |__||__|_|  /  \___  /   |__| |__|    \___  >|__|   |____// ____|
 *         \/                  \/       \/                     \/              \/     
 * 
 *           |\_|\
 *           | a_a\
 *           | | "]
 *       ____| '-\___
 *      /.----.___.-'\
 *     //        _    \
 *    //   .-. (GF)  /|
 *   |'|  /\:  .--  / \
 *  // |-/  \_/____/\/~|
 * |/  \ |  []_|_|_] \ |
 * | \  | \ |___   _\ ]_}
 * | |  '-' /   '.'  |
 * | |     /    /|:  | 
 * | |     |   / |:  /\
 * | |     /  /  |  /  \
 * | |    |  /  /  |    \
 * \ |    |/\/  |/|/\    \
 *  \|\ |\|  |  | / /\/\__\
 *   \ \| | /   | |__
 *        / |   |____)
 *        |_/
 * ----------------------------------------------------------------------------
 */

//Code Start
#include <bits/stdc++.h>
using namespace std;

//constant
#define PI acos(-1.0)
#define SZ 10000
#define mod 1000000007
//typedef
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double db;
typedef unsigned un;
typedef pair<int, int> pii;
typedef vector<int> vi;

//Debug Setting up
#define watch(x) cout << (#x) << "=" << x << endl
#define watch2(x, y) cout << (#x) << "=" << x << " & " << (#y) << "=" << y << endl;
#define watchara(wow)     \
    for (auto x : wow)    \
    {                     \
        cout << x << " "; \
    }                     \
    cout << "\n"

//defining fast_io
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

//defining something
#define F first
#define S second

//Main Function Start From Here
void solve()
{
    ull sum = 0;
    int n;
    cin >> n;

    ll ara[n];
    ll dp[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> ara[i];
        if (i)
        {
            dp[i] += dp[i - 1] + ara[i];
            dp[i] %= mod;
            sum %= mod;
            sum += dp[i - 1] * ara[i] * 1ull;
            sum %= mod;
        }
        else
        {
            dp[i] = ara[i];
        }
    }
    cout << sum << endl;
}

int main()
{
    fast_io;

    solve();

    return 0;
}