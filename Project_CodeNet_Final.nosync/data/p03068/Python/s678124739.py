n = int(input())
s = str(input())
k = int(input())

list_s = list(s)

target_chr = list_s[k - 1]

result = ""

for i in list_s:
    if i != target_chr:
        result += "*"
    else:
        result += i


print(result)