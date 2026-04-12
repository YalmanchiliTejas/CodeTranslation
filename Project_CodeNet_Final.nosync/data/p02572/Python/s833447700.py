N = map(int, input())
An = list(map(int, input().split()))
mnum = 10 ** 9 + 7
CumSum = An[0]
answer = 0
for i in range(1, len(An)):
    answer = (answer + CumSum * An[i]) 
    CumSum = (CumSum + An[i])
print(answer%mnum)