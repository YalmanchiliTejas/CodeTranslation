N = int(input())
S = input()
K = int(input())

target_c = S[K-1]

out_str = ""
for c in S:
    if c != target_c:
        out_str += "*"
    else:
        out_str += c

print(out_str)
