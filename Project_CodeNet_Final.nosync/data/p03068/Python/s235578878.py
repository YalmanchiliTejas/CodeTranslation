N = int(input())
S = str(input().strip())
K = int(input())
ret = []
target_char = S[K-1]
for char in S:
    if char == target_char:
        ret.append(target_char)
    else:
        ret.append("*")
print("".join(ret))