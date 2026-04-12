N = int(input())
S_arr = []

count_arr = []
for i in range(27):
    count_arr.append([])
    for j in range(N):
        count_arr[i].append(0)

for n in range(N):
    S = input()
    for c in S:
        count_arr[ord(c) - 97][n] += 1

min_count = []
for i in range(27):
    min_count.append(min(count_arr[i]))
# print(min_count)

ans = ''
for i in range(27):
    for _ in range(min_count[i]):
        ans += chr(i + 97)
print(ans)