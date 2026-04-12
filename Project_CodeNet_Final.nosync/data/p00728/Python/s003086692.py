ans_list = []

while True:
    n = int(input())
    if n == 0:
        break
    s = sorted([int(input()) for _ in range(n)])
    ans = sum(s[1:-1]) // (n-2)
    ans_list.append(ans)

for ans in ans_list:
    print(ans)
