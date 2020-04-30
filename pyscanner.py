import os
import glob

supported = ['<', '<<', '<=', '==', '>', '>=', '>>', '|', '||', '-', '-~', '!=', '/', '/~', '*', '*~', '&', '&&', '%', '+', '+~', 'abs', 'abs~', 'adc~', 'atan', 'atan2', 'b', 'bang', 'bendin', 'bendout', 'biquad~', 'bng', 'bp~', 'catch~', 'change', 'clip', 'clip~', 'cnv', 'cos', 'cos~', 'cpole~', 'ctlin', 'ctlout', 'czero~', 'czero_rev~', 'dac~', 'dbtopow', 'dbtopow~', 'dbtorms', 'dbtorms~', 'declare', 'del', 'delay', 'delread~', 'delwrite~', 'div', 'env~', 'exp', 'exp~', 'f', 'float', 'floatatom', 'ftom', 'ftom~', 'hip~', 'hradio', 'hsl', 'i', 'inlet', 'inlet~', 'int', 'line', 'line~', 'loadbang', 'log', 'lop~', 'makenote', 'max', 'max~', 'metro', 'min', 'min~', 'mod', 'moses', 'mtof', 'mtof~', 'nbx', 'noise~', 'notein', 'noteout', 'osc~', 'outlet', 'outlet~', 'pack', 'pgmin', 'pgmout', 'phasor~', 'pipe', 'poly', 'pow', 'pow~', 'powtodb', 'powtodb~', 'print', 'q8_rsqrt~', 'q8_sqrt~', 'r', 'r~', 'random', 'receive', 'receive~', 'rmstodb', 'rmstodb~', 'route', 'rpole~', 'rsqrt~', 'rzero~', 'rzero_rev~', 's', 's~', 'samphold~', 'samplerate~', 'sel', 'select', 'send', 'send~', 'sig~', 'sin', 'snapshot~', 'spigot', 'sqrt', 'sqrt~', 'swap', 'symbol', 'symbolatom', 't', 'table', 'tabosc4~', 'tabplay~', 'tabread', 'tabread~', 'tabread4~', 'tabwrite', 'tabwrite~', 'tan', 'tgl', 'throw~', 'timer', 'touchin', 'touchout', 'trigger', 'unpack', 'until', 'vcf~', 'vd~', 'vradio', 'vsl', 'wrap', 'wrap~']

files = []
path = './Hoclib/'

# r=root, d=directories, f = files
for r, d, f in os.walk(path):
    for file in f:
        if '.pd' in file:
            #print(file)
    #        files.append(os.path.join(r, file))
            file1 = open(path + file, 'r')
            count = 0
            res = []

            works = True

            while True:
                count += 1

                # Get next line from file
                line = file1.readline()
                linesplit = line.split()

                if(len(linesplit)>1):
                    #print(linesplit[1])
                    if(linesplit[1]=='obj'):
                        res = linesplit[4].strip(';')
                        if res not in supported:
                            works = False
                            #print("NOT! " + res)
                        #res.append(linesplit[4])
                # exit()

                # if line is empty
                # end of file is reached
                if not line:
                    break
                # print("Line{}: {}".format(count, line.strip()))

            if works:
                print(file)
            file1.close()
    break
