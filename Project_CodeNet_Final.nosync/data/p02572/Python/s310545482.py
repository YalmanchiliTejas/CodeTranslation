N = map(int, input())
An = list(map(int, input().split()))
mnum = 10 ** 9 + 7
CumSum = An[0] % mnum
answer = 0
for i in range(1, len(An)):
    answer = (answer + CumSum * An[i]) % mnum
    CumSum = (CumSum + An[i]) % mnum
print(answer)