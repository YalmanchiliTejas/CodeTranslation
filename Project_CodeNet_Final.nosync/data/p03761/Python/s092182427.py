n = int(input())
S = [input() for i in range(n)]
char = list("abcdefghijklmnopqrstuvwxyz")
char_count = {}
for i in range(26):
    char_count.setdefault(char[i], float("inf"))
    
for i in range(n):
    s = S[i]
    for j in range(26):
        char_count[char[j]] = min(char_count[char[j]], s.count(char[j]))
        
ans_list = []
for key, count in char_count.items():
    if count != float("inf") and count > 0:
        ans_list.append(key*count)
        
for ans in sorted(ans_list):
    print(ans, end="")