N = int(input())
Hs = list(map(int, input().split()))
print(len([i for i in range(0, len(Hs)) if all([Hs[j] <= Hs[i] for j in range(0, i)])]))