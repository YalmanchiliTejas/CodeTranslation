N = int(input())
s = list(input())
c_list = [['W','W'],['W','S'],['S','W'],['S','S']]

for c in c_list:
    for current in range(1,N):
        pre = current-1
        if ((c[current] == 'W' and s[current] == 'o') or (c[current] == 'S' and s[current] == 'x')):
            if(c[pre] == 'W'):
                c.append('S')
            else:
                c.append('W')
        elif ((c[current] == 'W' and s[current] == 'x') or (c[current] == 'S' and s[current] == 'o')):
            c.append(c[pre])
    if(c[0] == c[N]):
        if ((c[0] == 'W' and s[0] == 'o') or (c[0] == 'S' and s[0] == 'x')):
            if(c[1] != c[N-1]):
                print(''.join(c[0:N]))
                quit()
        else:
            if(c[1] == c[N-1]):
                print(''.join(c[0:N]))
                quit()
    """
    if ((c[0] == 'W' and s[0] == 'o') or (c[0] == 'S' and s[0] == 'x')):
        if (c[N-1] != c[1]):
            print(''.join(c[0:N]))
            quit()
    else:
        if (c[N-1] == c[1]):
            print(''.join(c[0:N]))
            quit()
    """
print(-1)
