def read():
    X = int(input())
    return X

def fun(X):
    if X >= 30:
        return 'Yes'
    else:
        return 'No'


if __name__ == '__main__':
    X = read()
    print(fun(X))