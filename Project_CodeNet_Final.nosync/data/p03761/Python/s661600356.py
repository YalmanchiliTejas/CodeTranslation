N = int(input())
S_list = []
min_length = 10000
for _ in range(N):
    st = input()
    S_list.append(st)
    min_length = min(min_length, len(st))
char_list = list("abcdefghijklmnopqrstuvwxyz")
total_counter = {char: 1e4 for char in char_list}
for i in range(N):
    string = S_list[i]
    for char in char_list:
        total_counter[char] = min(total_counter[char], string.count(char))


ans = ""

for char, count in total_counter.items():
    ans += char*count
    
print(ans)