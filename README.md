<h1 align="center">
     <a> Tripla Pitagórica MPI</a>
</h1>

<h3 align="center">
    Os códigos deste projeto tem como função executar o cálculo da tripla pitagórica de forma serial e de forma paralela utilizando MPI.
</h3>

<h4 align="left">
	🚧   Status: Concluído 🚀 🚧
</h4>

Tabela de conteúdos
=================
<!--ts-->
   * [O que é cada arquivo do projeto](#-o-que-é-cada-arquivo-do-projeto)
   * [Explicação geral do funcionamento dos códigos](#-explicação-geral-do-funcionamento-dos-códigos)
   * [Como executar o projeto](#-como-executar-o-projeto)
   * [Formato e conteúdos dos arquivos de saída](#-Formato-e-conteúdos-dos-arquivos-de-saída)
   * [Autores](#-autores)
<!--te-->


## 💻 O que é cada arquivo do projeto

O arquivo TriplasPitagoricasSerial.c contem o codigo serial para a execução do calculo das triplas na linguagem C. 

O arquivo TriplasPitagoricasParaleloMpi.c contem o codigo paralelo para a execução do calculo das triplas na linguagem C. 


## Explicação geral do funcionamento dos códigos

O código TriplasPitagoricasSerial.c possui uma função chamada tripla_pitagorica_c. Essa função possui três laços FOR aninhados que através de analise combinatoria realizam o calculo da quantidade de triplas pitagoricas. Além desse calculo, a função também cria o arquivo tripla.txt que irá receber o resultado dos calculos. Ao ser executado, o codigo define a variavel quantidade e seu respectivo valor. Essa variavel será utilizada dentro da função.

O código TriplasPitagoricasParaleloMpi.c ao ser executado define a variavel quantidade e seu respectivo valor, em seguida ele distribui a carga de trabalho entre os trabalhadores. Cada trabalhador ao encontrar uma tripla, ele resgistra a tripla em um vetor tridmiensional e incrementa o contador de triplas. Após finalizar, cada trabalhador envia para o mestre o seu vetor e a quantidade de triplas encontradas. Após receber as informações de todos os trabalhadores, o mestre faz a união de todos os vetores e somas os contadores, salvando no arquivo triplaParalelo.txt as triplas encontradas e quantidade total

## 🚀 Como executar o projeto


💡 Pré-requisitos: É necessário possuir um compilador GCC instalado.

Para executar o serial, o arquivo TriplasPitagoricasSerial.c deve ser copiado para o servidor e estando no local onde o arquivo foi salvo, deve ser executado o seguinte comando: gcc TriplasPitagoricasSerial.c -o TriplasPitagoricasSerial ./TriplasPitagoricasSerial

Para executar o serial, o arquivo TriplasPitagoricasParaleloMpi.c deve ser copiado para o servidor e estando no local onde o arquivo foi salvo, deve ser executado o seguinte comando: mpicc TriplaParaleloMpi.c -o TriplaParaleloMpi mpirun -np 2(aqui definimos o número de works/processos) ./TriplaParaleloMpi


## 📝 Formato e conteúdos dos arquivos de saída

Os arquivos são no formato txt.

## 🦸 Autores

<a href="https://github.com/osvaldolimeirasantos">
 <img style="border-radius: 50%;" src="https://avatars.githubusercontent.com/u/91644823?v=4" width="100px;" alt=""/>
 <sub><b>Osvaldo Limeira</b></sub></a> <a href="https://github.com/osvaldolimeirasantos" title="Rocketseat"></a>


<a href="https://github.com/jessicagreig1">
 <img style="border-radius: 50%;" src="https://avatars.githubusercontent.com/u/34080482?v=4" width="100px;" alt=""/>
 <sub><b>Jessica Cerqueira </b></sub></a> <a href="https://github.com/jessicagreig1" title="Rocketseat"></a>
 <br />


