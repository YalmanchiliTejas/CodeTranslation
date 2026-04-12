def function(X):
    if X < 30:
        return 'No'
    else:
        return 'Yes'


if __name__ == '__main__':
    X = int(input())
    print(function(X))