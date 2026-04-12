alphabet_small = [chr(i) for i in range(97, 97+26)] #アルファベッドの小文字
answer =[[] for i in range(26)]
n = int(input())
for i in range(n):
    S = input()
    box = [0]*26
    for s in S:
        box[alphabet_small.index(s)] += 1

    for i in range(26):
        answer[i].append(box[i])

ans = ""
for i in range(26):
    answer[i].sort()
    ans = ans + alphabet_small[i]*answer[i][0]

print(ans)