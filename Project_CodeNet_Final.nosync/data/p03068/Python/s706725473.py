n=int(input())
S=input()
i=int(input())
for s in S:
    print(s if s==S[i-1] else "*",end="")