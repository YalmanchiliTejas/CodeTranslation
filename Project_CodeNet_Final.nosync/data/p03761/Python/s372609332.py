n = int(input())
box = [[0 for _ in range(n)] for _ in range(26)]
for i in range(n):
    s = input()
    for j in range(len(s)):
        box[ord(s[j]) - 97][i] += 1
strs = ''
for i in range(26):
    strs += (chr(97 + i)) * min(box[i])
print(strs)