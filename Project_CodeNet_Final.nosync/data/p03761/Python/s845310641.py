from collections import Counter
n=int(input())
alpha = 'abcdefghijklmnopqrstuvwxyz'
ans=Counter(input())
for _ in range(n-1):
    temp=Counter(input())
    for char in alpha:
        ans[char]=min(ans[char],temp[char])
for char in alpha:
    for _ in range(ans[char]):
        print(char,end='')