import glob

# 問題ごとのディレクトリのトップからの相対パス
REL_PATH = 'ABC\\95\\C'

# テスト用ファイル置き場のトップ
TOP_PATH = 'C:\\AtCoder'


class Common:

    problem = []
    index = 0

    def __init__(self, rel_path):
        self.rel_path = rel_path

    def initialize(self, path):
        file = open(path)
        self.problem = file.readlines()
        self.index = 0
        return

    def input_data(self):
        try:
            IS_TEST
            self.index += 1
            return self.problem[self.index-1]

        except NameError:
            return input()

    def resolve(self):
        pass

    def exec_resolve(self):
        try:
            IS_TEST
            for path in glob.glob(TOP_PATH + '\\' + self.rel_path + '/*.txt'):
                print("Test: " + path)
                self.initialize(path)
                self.resolve()
                print("\n\n")
        except NameError:
            self.resolve()


class Solver(Common):

    def resolve(self):

        q = [int(i) for i in self.input_data().split()]
        A = q[0]
        B = q[1]
        C = q[2]
        X = q[3]
        Y = q[4]

        if 2*C > A+B:
            result = A * X + B * Y
        else:
            if X > Y:
                result = C * Y * 2
                if A > C * 2:
                    result += (X - Y) * C * 2
                else:
                    result += (X -Y) * A

            else:
                result = C * X * 2
                if B > C * 2:
                    result += (Y - X) * C * 2
                else:
                    result += (Y -X) * B

        print(str(result))


solver = Solver(REL_PATH)
solver.exec_resolve()
