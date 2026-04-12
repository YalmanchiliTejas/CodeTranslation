def ABC_64_A():
    r,g,b = map(int, input().split())

    kazu = int(r*100 + g*10 + b)
    
    if kazu%4 == 0:
        print('YES')
    else:
        print('NO')

if __name__ == '__main__':

    ABC_64_A()