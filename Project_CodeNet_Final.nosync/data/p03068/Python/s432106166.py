n=int(input())
s=input()
k=s[int(input())-1]
print("".join([t if t==k else "*" for t in s]))