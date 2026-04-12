input()
s=input()
k=int(input())
print(*[x if x==s[k-1] else '*' for x in s],sep='')