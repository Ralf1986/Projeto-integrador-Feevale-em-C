# Projeto integrador Universidade Feevale

## 1.    INTRODUÇÃO

Os computadores atuais saíram das mesas de trabalho e foram espalhados por todos os lados, indo parar
inclusive nos bolsos dos usuários. Os dispositivos móveis, como SmartWatches e SmartPhones, são
basicamente computadores miniaturizados que executam Sistemas Operacionais e trocam dados entre si.
Eles utilizam os mesmos protocolos e interfaces de rede que os computadores Desktop usam há pelo
menos uma década. Os algoritmos, os modelos de programação, as estruturas de dados e as tecnologias
de rede são basicamente as mesmas.

A partir do contexto relatado, este Projeto Integrador cria um cenário que permite que você aplique
os conteúdos estudados em Comunicação de Dados, Estruturas de Dados I e Sistemas Operacionais na
elaboração de um projeto com finalidade específica.

Relacionando os temas dos três componentes estudados, será desenvolvida uma aplicação para monitoramento
das interfaces de rede de computadores, executando o sistema operacional Linux, identificando e registrando
os eventos de conexão e desconexão do cabo de rede em sua interface física.

## 2.    OBJETIVO GERAL DO PROJETO INTEGRADOR

Utilizar os conceitos desenvolvidos nos componentes curriculares do módulo e desenvolver uma análise de logs
de rede (Comunicação de Dados) de um Sistema Operacional (Sistemas Operacionais), para que os eventos
identificados possam ser armazenados/processados de forma estruturada (Estrutura de Dados I).

## 3.     OBJETIVOS ESPECÍFICOS:

Compreender as estratégias de registro de eventos aplicadas/ empregadas por sistemas operacionais baseados em UNIX;
Identificar a ocorrência de eventos relacionados às interfaces de rede ETHERNET, presentes no equipamento monitorado;
Desenvolver estruturas de dados compatíveis com os eventos observados.
## 4.    ESTRUTURA DO PROJETO:

O Projeto deve ser estruturado em 3 partes, descritas a seguir:

### Etapa 1- Investigação de Logs relacionados a comunicação de dados do sistema operacional e Análise do syslog

 Tarefa

A partir dos tópicos relacionados abaixo, grave um vídeo de 4 minutos trazendo suas percepções após
analisar e estudar os logs produzidos pelo Sistema Operacional Linux. Utilize o tempo do seu vídeo para
elucidar os tópicos relacionados, fazendo uma síntese dos conceitos e apresentando suas percepções e
conclusões sobre os mesmos.

Identificar os logs produzidos pelo sistema operacional e seus propósitos.
Mostrar como os logs são gerados e onde são armazenados.
Identificar os logs utilizados para manter os registros dos eventos de conexão e desconexão de rede.
Analisar as estruturas dos logs.
Apontar quais aplicações deixam registros nos logs.
Comentar o formato básico dos registros de log.
Formato de entrega: vídeo ou link do vídeo com no máximo 4 minutos.
Critérios de avaliação:
domínio do tema;
profundidade de argumentação;
coerência nas respostas;
originalidade.

Formatato do arquivo de "syslog":

Sep 18 12:38:45 ralf-MS-7817 NetworkManager[826]: <info>  [1695051525.7846] manager: NetworkManager state is now CONNECTED_GLOBAL

### Etapa 2 – Estrutura(s) de dados

 Tarefa:

A partir do estudo realizado na etapa 1, planejar um programa para ler os eventos de conexão e desconexão
de rede (existentes no syslog) e inseri-los em estruturas de dados na memória. Antes de iniciar a
programação, nessa etapa deve-se elaborar um vídeo de no máximo 4 minutos para elucidar os seguintes pontos:

Estratégias utilizadas para coleta dos dados referentes aos eventos de conexão e desconexão de rede.
Estrutura(s) de dados utilizada para armazenar os registros dos eventos de conexão de rede.
Funções utilizadas para manipular a(s) estrutura(s) de dados criada(s). É necessário que,
no mínimo, quatro funções sejam elaboradas:
adicionar um evento à estrutura;
remover um evento da estrutura;
listar todos os eventos da estrutura;
o implementar no mínimo mais uma função (de livre escolha do aluno), vinculada a manipulação dos eventos.
Formato de entrega: vídeo ou link do vídeo com no máximo 4 minutos.

Critérios de avaliação:
domínio do tema;
profundidade de argumentação;
coerência na escolha das estratégias e estrutura(s) de dados;
originalidade.

### Etapa 3 - Implementação

 Tarefa:

Baseado na etapa 2, desenvolver uma aplicação (programa) que, ao monitorar os logs do Sistema Operacional
(especificamente syslog), utilize a(s) estrutura(s) de dados propostas na etapa 2 para armazenar os eventos
de rede que apontem a conexão e desconexão física do cabo de rede nas interfaces Ethernet.
Você deve enviar o arquivo com o código fonte de sua solução, documentado com comentários pertinentes
dentro do próprio código.
Deve ser desenvolvido também um vídeo ou link de um vídeo demonstrativo, produzido pelo aluno, executando
e comentando o funcionamento do software implementado. O vídeo poderá ter no máximo 4 minutos.
Formato de entrega: Realize as tarefas da etapa 3 adicionando os arquivos (código fonte e vídeo ou link do vídeo)
em um zip ou rar.
Critérios de avaliação:
domínio do tema;
profundidade de argumentação;
o código deve, obrigatoriamente, compilar e executar;
originalidade.
Observação: o código deve ser implementado na linguagem C/C++ ou Java.
