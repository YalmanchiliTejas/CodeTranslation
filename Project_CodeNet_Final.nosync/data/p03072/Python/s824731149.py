N = int(input())
H_s = list(map(int, input().split()))
highest = 0
answer = 0
for H in H_s:
    if H >= highest:
        answer += 1
        highest = H
print(answer)