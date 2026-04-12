n=input()
s=input()
k=int(input())
for i in range(int(n)):
    print(s[i] if s[k-1] == s[i] else "*",end="")
print()
