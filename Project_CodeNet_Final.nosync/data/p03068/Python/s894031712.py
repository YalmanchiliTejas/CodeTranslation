N = int(input())
S = input()
K = int(input())

no_change = S[K-1]

for i in S:
    if i != no_change:
        print("*",end = "")
    else:
        print(i,end="")
print()