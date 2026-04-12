S_list = list(map(int,input().split()))

r, g, b = S_list[0], S_list[1], S_list[2]
if (10 * g + b) % 4 == 0 :
    result = "YES"
else:
    result = "NO"
print(result)
