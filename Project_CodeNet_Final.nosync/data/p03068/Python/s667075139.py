n=int(input())
s=input()
k=int(input())
print(''.join([x if x==s[k-1] else '*' for x in s]))