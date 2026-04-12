def judge():
    for i in range(1, n):
        before = list[i-1]
        l = s[i]
        if l == 'o':
            if list[i] == 'S':
                if before == 'S':
                    list.append('S')
                else:
                    list.append('W')
            else:
                if before == 'S':
                    list.append('W')
                else:
                    list.append('S')
        else:
            if list[i] == 'S':
                if before == 'S':
                    list.append('W')
                else:
                    list.append('S')
            else:
                if before == 'S':
                    list.append('S')
                else:
                    list.append('W')
    if list[0] == list[n]:
        if list[0] == 'S':
            if s[0] == 'o' and list[1] == list[n-1] or s[0] == 'x' and list[1] != list[n-1]:
                list.pop()
                print("".join(list))
                exit()
        elif list[0] == 'W':
            if s[0] == 'x' and list[1] == list[n-1] or s[0] == 'o' and list[1] != list[n-1]:
                list.pop()
                print("".join(list))
                exit()

n = int(input())
s = input()

list = ['S', 'S']
judge()
list.clear()
list = ['S', 'W']
judge()
list.clear()
list = ['W', 'S']
judge()
list.clear()
list = ['W', 'W']
judge()
list.clear()
print('-1')