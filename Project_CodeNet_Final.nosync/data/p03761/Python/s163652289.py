n = int(input())
dict = {}
for i in range(97, 123):
    dict[chr(i)] = 100
for _ in range(n):
    s = input()
    for i in range(97, 123):
        count = s.count(chr(i))
        dict[chr(i)] = min(count, dict[chr(i)])
ans = ''
for i in range(97, 123):
    if dict[chr(i)] != 100:
        ans +=  chr(i) * dict[chr(i)]
print(ans)