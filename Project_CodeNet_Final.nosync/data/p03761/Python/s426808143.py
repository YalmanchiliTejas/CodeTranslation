def list_difference(list1, list2):
    result = list1.copy()
    for value in list2:
        if value in result:
            result.remove(value)

    return result

n = int(input())
list_S = [list(input()) for _ in range(n)]


ans = []
while True:
    a = set(list_S[0])
    for i in range(1, n):
        a = set("".join(list_S[i])) & a
        if len(a) == 0:
            break

    for i in range(n):
        list_S[i] = list_difference(list_S[i], list(a))


    if len(a) == 0:
        break

    a = list(a)
    for s in a:
        ans.append(s)

ans.sort()
print("".join(ans))