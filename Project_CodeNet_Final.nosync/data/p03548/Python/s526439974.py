def ABC_78_B():
    X,Y,Z = map(int, input().split())
    sum=0
    N=0
    while sum<= X:
        sum = Y*N+Z*(N+1)
        N+=1  
    print(N-2)


if __name__ == '__main__':

    ABC_78_B()