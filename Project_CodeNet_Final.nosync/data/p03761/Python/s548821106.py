from collections import Counter
n = int(input())
work = [Counter(list(input())) for i in range(n)]
temp = work[0]
for el in work[1:]:
    for k, v in temp.items():
        if k in el.keys():
            temp[k] = v if el[k] > v else el[k]
        else:
            temp[k] = 0
result = ""
for k, v in temp.items():
    if v > 0:
        result += k*v
print("".join(sorted(result)))