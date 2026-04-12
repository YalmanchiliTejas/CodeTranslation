input_text = list(map(int, input().split()))
# print(input_text)

target = int("".join(map(str,input_text)))
# print(target)

if target%4 == 0:
    print("YES")
else:
    print("NO")