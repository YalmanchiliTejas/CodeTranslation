N = int(input())

def check():
    if N==3 or N==5 or N==7:
        return True
    return False
if check():
    print('YES')
else:
    print('NO')