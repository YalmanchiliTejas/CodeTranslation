N = int(input())
S = input()
k = int(input())
t = S[k-1]
for s in S:
    if s != t:
        print("*", end="")
    else:
        print(s, end="")