N=int(input())
S=input()
t=S[int(input())-1]

ans = [i if i==t else "*" for i in S]
print("".join(ans))