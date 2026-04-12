N = int(input())
mountains = list(map(int, input().split()))

max_height = mountains[0]
ans = 0
for mountain in mountains:
    if mountain >= max_height:
        ans += 1
    max_height = max(max_height, mountain)
print(ans)