N = int(input())
len_min = 51
min_i = 51
S = []

for i in range(N):
    Si = input()
    if len_min > len(Si):
        min_i = i
        len_min = len(Si)
    S.append(Si)

# 一番文字数が少ないSiに含まれる文字をmemoに記録して、
# 他の文字列にも含まれているかどうかを確認していく。
# 同じ文字が複数入っている場合を考慮してa1,a2と数字をつける。
memo = {}
for char in S[min_i]:
    count_char = S[min_i].count(char)
    for i in range(1, count_char+1):
        char_num = char+str(i)
        memo[char_num] = 1

# print(memo)
# ->{'c1': 1, 'b1': 1, 'a1': 1, 'a2': 1}

del S[min_i]

for Si in S:
    checked_char = {}
    for char in Si:
        if char in checked_char:
            continue
        count_char = Si.count(char)
        for i in range(1, count_char+1):
            char_num = char+str(i)
            try:
                memo[char_num] += 1
            except:
                pass
        checked_char[char] = None


ans = []
for char in memo:
    if memo[char] == N:
        ans.append(char[0])

ans.sort()
print("".join(ans))
