N = int(input())

def pay():
    fee = 800
    reward = 200

    x = 800 * N
    y = N // 15 * 200
    return(x-y)

if __name__ == '__main__':
    print(pay())