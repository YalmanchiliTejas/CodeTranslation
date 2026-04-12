n=int(input())
s=input()
k=int(input())
ss=[x if x==s[k-1] else "*" for x in s]
print("".join(ss))