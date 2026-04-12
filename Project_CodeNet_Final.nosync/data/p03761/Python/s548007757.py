N = int(input())
mem = [100 for i in range(26)]
for i in range(N):
    s = input()
    arr = [0 for i in range(26)]
    for c in s:
        ci = ord(c) - ord('a')
        arr[ci] += 1
    for i in range(26):
        mem[i] = min(mem[i], arr[i])

ans = ''
for i in range(26):
    c = chr(i + ord('a'))
    ans += c * mem[i]
print(ans)
