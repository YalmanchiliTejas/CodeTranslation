import string
alphabets = string.ascii_lowercase   
n = int(input())
S = [input() for _ in range(n)]
counter = {}

for alphabet in alphabets:
    alphabet_count = [s.count(alphabet) for s in S]
    counter[alphabet] = min(alphabet_count)
ans = ""
for alphabet, count in counter.items():
    ans += alphabet*count
print("".join(sorted(ans)))