n = int(input())
alphabets = "abcdefghijklmnopqrstuvwxyz"
s = [input() for _ in range(n)]
NUM = {}
ans = ""


for char in alphabets:
    num_char = 100
    for S in s:
        num_char = min(num_char, S.count(char))
    NUM[char] = num_char

NUM = sorted(NUM.items())

for i in NUM:
    ans += i[0]*i[1]
print(ans)