X,Y,Z = map(int, input().split())

total = Z
answer = 0
for i in range(10**9 + 1):
    if total+(Y+Z) <= X:
        total += Y+Z
        answer += 1
    else:
        print(answer)
        exit()