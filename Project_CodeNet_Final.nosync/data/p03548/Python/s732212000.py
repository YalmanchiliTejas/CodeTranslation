def resolve():
    X, Y, Z = list(map(int, input().split()))
    print((X-Z)//(Y+Z))
    

            

if '__main__' == __name__:
    resolve()