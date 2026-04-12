N = int(input())
a = list(map(int, input().split()))
check_num = a[0]
answer = 0
for i in range(N):
    if check_num <= a[i]:
        check_num = a[i]
        answer += 1

print(answer)