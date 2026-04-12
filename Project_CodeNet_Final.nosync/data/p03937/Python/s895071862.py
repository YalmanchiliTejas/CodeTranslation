h, w = map(int, input().split())
cnt = 0
for i in range(h):
    s = input()
    for j in range(len(s)):
    	if s[j] == "#": cnt += 1
print("Possible") if cnt == h + w - 1 else print("Impossible")
