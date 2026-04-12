# coding: utf-8
# Your code here!

import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline #文字列入力のときは注意

n = int(input())
s = input()

#print(s)
def solve(a,b): #a: n-1th b:0th 
    res = [a,b]
    for i in s:
        if i == "o":
            c = (res[-1]+res[-2])%2
        else:
            c = (1+res[-1]+res[-2])%2
        res.append(c)
#    print(a,res)
    if res[-2] == a and res[-1] == b:
        ans = ["W" if i else "S" for i in res[1:-1]]
        print("".join(ans))
        exit()
    
    
for a in range(2):
    for b in range(2):
        solve(a,b)
        
print(-1)