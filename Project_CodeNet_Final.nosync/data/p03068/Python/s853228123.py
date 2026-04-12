N = int(input())
S = input()
K = int(input())

a = S[K - 1]

for i in range(len(S)) :
    if S[i] != a :
        print('*', end="")
    else :
        print(S[i], end="")
print()
